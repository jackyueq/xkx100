//recruit.c
// ������������ؤ����Ӳ���Ͷ���ɡ�

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob, old_rec;
	mapping family;
	int i,fealty;
	string temp;
	int student_num;
	object feng,room;
	int flag;

	if (!arg)
		return notify_fail("ָ���ʽ��recruit|shou [cancel]|<����>\n");
	if (arg=="cancel")
	{
		old_rec = me->query_temp("pending/recruit");
		if( !objectp(old_rec) )
			return notify_fail("�����ڲ�û����¼�κ���Ϊ���ӵ���˼��\n");
		write("��ı����ⲻ����" + old_rec->name() + "Ϊ�����ˡ�\n");
		tell_object(old_rec, me->name()+"�ı����ⲻ������Ϊ�����ˡ�\n");
		me->delete_temp("pending/recruit");
		return 1;
	}
          if(arg=="corpse"||arg=="skeleton")
           	return notify_fail("�����һ�㣬�ǲ��������\n");
//        if(!living(ob)||ob->query_temp("noliving"))
//              return notify_fail("�����һ�㣬�ǲ����ˡ�\n");

	if (!(ob=present(arg,environment(me))))
		return notify_fail("������˭�����ӣ�\n");
	if (ob==me)
		return notify_fail("���Լ�Ϊ���ӣ�������....����û���á�\n");
	if (ob->is_apprentice_of(me))
	{
		message_vision("$N����$n��ͷ��˵��������ͽ������\n", me, ob);
		return 1;
	}
	if (!me->query("family"))
		return notify_fail("�㲢�������κ����ɣ�������ȼ���һ�����ɣ����Լ���һ��������ͽ��\n");
	if( ob->query("party") &&
		ob->query("party/party_name") == HIC"ؤ��"NOR &&
		me->query("family/family_name") != "ؤ��")
	{
		message_vision("$N���˿�$n��ҡ��ҡͷ����������ؤ���д����ӣ����ǻ�ؤ��ȥ�ɡ���\n", me, ob);
		return 1;
	}
	if (me->accept_betrayer(ob))
	{
		message_vision("$N���˿�$n����Ȼ��ҡ��ҡͷ�����������Է�������Ե�нӱ����²�������Ϊ֮�ɡ���\n", me, ob);
		return 1;
	}
// If the target is willing to apprentice us already, we do it.
	if ((object)ob->query_temp("pending/apprentice") == me)
	{
  	if (ob->query("detach/"+me->query("family/family_name"))>0)
  	{
		message_vision("$N���˿�$n��ҡ��ҡͷ�������㵱���Ȼ�뿪��"+me->query("family/family_name")+"�������ֺαػ�������\n", me, ob);
		return 1;
		}
		if (!living(ob) || ob->query_temp("noliving") )
		{
			message_vision("$N������$nΪ���ӡ�\n\n����������$n��Ȼû�а취�а�ʦ֮��\n\n",me, ob);
			return 1;
		}
// follow modified by elon 09-10-95 to fix a bug in 1st time recruit
		if((ob->query("family")) && (me->query("family")) &&
			( (string)me->query("family/family_name") !=
			(string)ob->query("family/family_name") ) )
		{
// Modified by That Oct.17 1997
			if (ob->query("title")=="��ʿ" ||ob->query("combat_exp")<100000) 
			{
   	    ob->add("detach/"+ob->query("family/family_name"),1);
				message_vision("$N��������Ͷ��$n���£���\n\n$N����������$n���������ؿ����ĸ���ͷ���е�����ʦ������\n\n$N����ȴ����������裡\n\n", ob, me);
				ob->set_temp("fealty_temp",0);
				ob->set("score", 0);
				ob->add("betrayer", 1);
		    ob->delete("perform");		
			}
			else
			{
				message_vision("$N������$n�����ţ��֣�������ô�ߣ��ٺ٣��ҿɲ��������ˡ�\n", me, ob);
				return 1;
			}
		}
		else
		{
			message_vision("$N������$nΪ���ӡ�\n\n$n����������$N���������ؿ����ĸ���ͷ���е�����ʦ������\n", me, ob);
 		}
		if ((string)ob->query("family/master_id")=="feng qingyang")
		{
			room = find_object("/d/huashan/xiaofang");
			if (!objectp(room)) room = load_object("/d/huashan/xiaofang");
			feng = present("feng qingyang",room);
			if (!objectp(feng)) 
			{
				feng = new("/kungfu/class/huashan/feng");
				flag = 1;
			}
			feng->delete("students/"+ob->query("id"));
			feng->set("no_accept/"+ob->query("id"),1);
			feng->save_data();
			if (flag == 1) destruct(feng);
		}
		me->recruit_apprentice(ob);
		ob->delete_temp("pending/apprentice");
		fealty=(int)(ob->query_temp("fealty_temp"));
		ob->set("family/fealty",fealty);
		ob->delete_temp("fealty_temp");

		if ((ob->query("class")!="bonze") &&
			(me->query("class")!="bonze") &&
			(ob->query("class")!="lama") &&
			(me->query("class")!="lama") &&
			(ob->query("class")!="quanzhen") &&
			(me->query("class")!="quanzhen") &&
			(ob->query("class")!="eunach") &&
			(me->query("class")!="eunach"))
			ob->set("class",me->query("class"));
	
		write("��ϲ��������һ�����ӣ�\n");
		family = ob->query("family");
		tell_object( ob, sprintf("��ϲ����Ϊ%s�ĵ�%s�����ӡ�\n", family["family_name"], chinese_number(family["generation"]) ));
		return 1;
	}
	else
	{
		old_rec = me->query_temp("pending/recruit");
		if( ob==old_rec )
		return notify_fail("������" + ob->name() + "Ϊ���ӣ����ǶԷ���û�д�Ӧ��\n");
		else if( objectp(old_rec) )
			{
				write("��ı����ⲻ����"+old_rec->name()+"Ϊ�����ˡ�\n");
				tell_object(old_rec,me->name()+"�ı����ⲻ������Ϊ�����ˡ�\n");
			}
		me->set_temp("pending/recruit", ob );
		message_vision("\n$N��Ҫ��$nΪ���ӡ�\n", me, ob);
		tell_object(ob, YEL "�����Ը���" + me->name() + "Ϊʦ������ apprentice ָ�\n" NOR);
		return 1;
	}
}


int help(object me)
{
	write(@HELP
ָ���ʽ : recruit|shou [cancel]|<����>

    ���ָ����������ĳ��Ϊ���ӣ�����Է�Ҳ��ӦҪ����Ϊʦ�Ļ���

See Also: apprentice
HELP
	);
	return 1;
}
