// apprentice.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob, old_app;
	mapping family, skills;
	int i,fealty;
	string *skname;
	object room;
	object feng;
	int flag;
	
	seteuid(getuid());
	if (me->is_busy()) return notify_fail("��������æ���ء�\n");
	if( !arg ) return notify_fail("ָ���ʽ��apprentice | bai [cancel]|<����>\n");
	if( arg=="cancel" )
	{
		old_app = me->query_temp("pending/apprentice");
		if( !objectp(old_app) )
			return notify_fail("�����ڲ��ް��κ���Ϊʦ����˼��\n");
		write("��ı����ⲻ���" + old_app->name() + "Ϊʦ�ˡ�\n");
		tell_object(old_app, me->name() + "�ı����ⲻ�����Ϊʦ�ˡ�\n");
		me->delete_temp("pending/apprentice");
		return 1;
	}
	if( !(ob = present(arg, environment(me))) || !ob->is_character() )
		return notify_fail("�����˭Ϊʦ��\n");
	if( !living(ob) || ob->query_temp("noliving") )
		return notify_fail("������Ȱ�" + ob->name() + "Ū�ѡ�\n");
	if( ob==me ) 
		return notify_fail("���Լ�Ϊʦ��������....����û���á�\n");
	if( me->is_apprentice_of(ob) )
	{
		message_vision("$N������������$n��ͷ�밲���е�����ʦ������\n", me, ob);
		return 1;
	}
	if( !mapp( ob->query("family") ) )
		return notify_fail( ob->name() + "�Ȳ�����κ����ɣ�Ҳû�п�ɽ���ɣ����ܰ�ʦ��\n");

	// If the target is willing to recruit us already, we do it.
	if( (object)ob->query_temp("pending/recruit") == me )
	{
		if (me->query("detach/"+ob->query("family/family_name"))>0)
		{
			ob->delete_temp("pending/recruit");
			message_vision("$N���˿�$n��ҡ��ҡͷ�������㵱���Ȼ�뿪��"+ob->query("family/family_name")+"�������ֺαػ�������\n", ob, me);
			return 1;
		}

		fealty=(int)(me->query("family/fealty"));
		me->set_temp("fealty_temp",fealty);
		if( (me->query("family"))&&(string)me->query("family/family_name") !=
			(string)ob->query("family/family_name") )
		{
			if (me->query("combat_exp")>10000)
			{
				message_vision("$N����̫���ˣ����ܸ�Ͷ$n���£���\n\n",me,ob);
				return 0;
			}
			message_vision("$N��������ʦ�ţ���Ͷ��$n���£���\n\n$N����������$n���������ؿ����ĸ���ͷ���е�����ʦ������\n\n", me, ob);
			me->add("detach/"+me->query("family/family_name"),1);
			me->set("family/fealty", 0);
			me->set_temp("fealty_temp",0);
			me->add("betrayer", 1);
		}
		else 
		message_vision("$N������$nΪʦ��\n\n$N����������$n���������ؿ����ĸ���ͷ���е�����ʦ������\n\n", me, ob);
		if ((string)me->query("family/master_id")=="feng qingyang")
		{
			room = find_object("/d/huashan/xiaofang");
			if (!objectp(room)) room = load_object("/d/huashan/xiaofang");
			feng = present("feng qingyang",room);
			if (!objectp(feng)) 
			{
				feng = new("/kungfu/class/huashan/feng");
				flag = 1;
			}
			feng->delete("students/"+me->query("id"));
			feng->set("no_accept/"+me->query("id"),1);
			feng->save_data();
			if (flag == 1) destruct(feng);
		}
		ob->recruit_apprentice(me);
		ob->delete_temp("pending/recruit");

		tell_object(ob, "��ϲ��������һ�����ӣ�\n");
		family = me->query("family");
		printf("��ϲ����Ϊ%s�ĵ�%s�����ӡ�\n", me->query("family/family_name"), chinese_number( me->query("family/generation")));
		fealty=(int)(me->query_temp("fealty_temp"));
		me->set("family/fealty",fealty);
		me->delete_temp("fealty_temp");
		//me->set_temp("faint",200);
		return 1;
	}
	else
	{
		fealty=(int)(me->query("family/fealty"));
		me->set_temp("fealty_temp",fealty);
		old_app = me->query_temp("pending/apprentice");
		if( ob==old_app )
			return notify_fail("�����" + ob->name() + "Ϊʦ�����ǶԷ���û�д�Ӧ��\n");
		else
			if( objectp(old_app) )
			{
				write("��ı����ⲻ���" + old_app->name() + "Ϊʦ�ˡ�\n");
				tell_object(old_app, me->name() + "�ı����ⲻ�����Ϊʦ�ˡ�\n");
			}

		message_vision("$N��Ҫ��$nΪʦ��\n", me, ob);
		me->set_temp("pending/apprentice", ob );
		if( userp(ob) )
		{
			tell_object(ob, YEL "�����Ը����" + me->name() + "Ϊ���ӣ��� recruit ָ�\n" NOR);
		}
		else ob->attempt_apprentice(me);
		//fealty=(int)(me->query_temp("fealty_temp"));
		//me->set("family/fealty",fealty);
		//me->delete_temp("fealty_temp");
		me->set_temp("faint",200);
		return 1;
	}
}


int help(object me)
{
	write(@HELP
ָ���ʽ : apprentice|bai [cancel]|<����>
 
    ���ָ���������ĳ��Ϊʦ������Է�Ҳ��ӦҪ����Ϊͽ�Ļ����ͻ�����
�а�ʦ֮�񣬵�Ҫ�ȵ��Է��ã��������������ָ������Ϊ���Ӳ���
��ʽ��ʦ����ע�����Ѿ�����ʦ�����ֱ���ʦ��Ͷ��������£�������������
��Ӱ�죬��ʦ�����Ժ��ѧϰ��ǰ;�������Ӱ�졣

    ��������ʦ��ʹ�����ָ�������ʦ���밲��
    ���ʹ�õĲ���������������ȡ����ղŵİ�ʦ֮�Ҫ�ڶԷ���
Ӧ֮ǰʵ��Ŷ������

    ���ΣУ�ֻ����ƽ����պͱ��ɵ��ӣ��������ܱ��ɵ��ӣ���ʦ���г�
���ģ�����ѡ������ʱҪС�ġ�

��ο����ָ�� expell��recruit
HELP
	);
	return 1;
}
