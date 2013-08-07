// guard.c
// Modified by Spacenet@FLXT 11.30.1999

#include <ansi.h>;
inherit F_CLEAN_UP;

mapping default_dirs = ([
	"north":        "��",
	"south":        "��",
	"east":	        "��",
	"west":	        "��",
	"northup":      "����",
	"southup":      "�ϱ�",
	"eastup":       "����",
	"westup":       "����",
	"northdown":    "����",
	"southdown":    "�ϱ�",
	"eastdown":	"����",
	"westdown":	"����",
	"northeast":    "����",
	"northwest":    "����",
	"southeast":    "����",
	"southwest":    "����",
	"up":           "��",
	"down":	        "��",
	"out":	        "��",
	"in" :          "��",
	"enter" :       "����",
]);

int main(object me, string arg)
{
	string dir;
	object ob, *guards, env;
	mixed old_obj, old_dir; 

	if( me->is_busy() )
		return notify_fail("������û�а취����ȥ�������£�\n");
	if( me->query("jing") < 200 || me->query("qi") < 200 )
		return notify_fail("������û���㹻�ľ�����ȥ�������£�\n");
	old_dir = me->query_temp("guardto");  
	old_obj = me->query_temp("guardfor");  
	env = environment(me);
	if(env->query("no_guard") || env->query("no_fight"))
		return notify_fail("���޷��������ػ�ʲô��\n");

	if( !arg || arg=="" )
	{
		if( !old_obj && !old_dir)
			return notify_fail("ָ���ʽ��guard <����> | <��Ʒ> | <����>\n");
		if( objectp(old_obj) )
			if(living(old_obj) && !old_obj->query_temp("noliving"))
				write("�������ػ���"+old_obj->name()+"��\n");
			else
				write("��������"+old_obj->name()+"һ�ԣ���ֹ�������ߡ�\n");
		else write( "��������ס�� "+default_dirs[old_dir]+" �ķ��򣬲�׼�κ����뿪��\n");
		return 1;
	}

	ob = present(arg, env);
	if( ob )
	{
		if( ob==me )
			return notify_fail("�����Լ�������˵��Ҳ�ᣬ�԰ɡ�\n");
		me->delete_temp("guardto", ob);
		me->set_temp("guardfor", ob);
	}
	else
		if( env->query("exits/" + arg) )
		{
			if( env->query("no_fight") )
				return notify_fail("���ﲻ׼ս����Ҳ��׼��ס����ȥ·��\n");
		}
		else
			if( arg == "cancel" )
			{
				if (!old_obj)
					return notify_fail("�㱾����û���ػ�ʲô��������\n");
				write("ʲôҲ�����ػ��ˣ����Ǻ����ɡ�\n");
				me->delete_temp("guardfor");
				guards = old_obj->query_temp("guarded");
				guards -= ({ me });
				old_obj->set_temp("guarded", guards);
				return 1;
			}
			else
				return notify_fail("��Ҫ�ػ�˭��ʲô�����ǰ����ĸ�����\n");

	if( objectp(old_obj) )
	{
		guards = old_obj->query_temp("guarded");
		guards -= ({ me });
		old_obj->set_temp("guarded", guards);
		if( living(old_obj) && !old_obj->query_temp("noliving") )
		{
			if (old_obj != ob)  
				message_vision("$N���ٱ���$n�ˡ�\n",me,old_obj);
		}
	}
	else
	{
		env->delete("guarded/"+old_dir);
		me->delete_temp("guardto");
		if (old_dir && arg != old_dir)
			message_vision( "$N���ٰ���"+default_dirs[old_dir]+"��������ˡ�\n",me);
		me->enable_path();
	}

	if( objectp(ob) )
	{
		ob->add_temp("guarded", ({ me }) );
		if( living(ob) && !ob->query_temp("noliving") )
		{
			if (ob == old_obj)  
				message_vision("$N���ڱ���$n��\n", me, ob);
			else message_vision("$N��ʼ����$n��\n", me, ob);
		}
		else
		{
			if (ob == old_obj)  
				message_vision("$Nվ�����ϵ�$nһ�����ţ��������ȡ�ߡ�\n", me, ob);
			else message_vision("$N�������ŵ��ϵ�$n��\n", me, ob);
		}
	}
	else
	{
		if( env->query("guarded/"+arg))
		{
			dir = env->query("guarded/"+arg);
			if( ob = present(dir, env) )
				return notify_fail(HIR+ob->query("name")+"�Ѿ���ס����"+default_dirs[arg]+"ȥ�ĳ�·��\n"NOR);
		}
		me->start_busy(1);
		me->set_temp("guardto", arg);
		me->delete_temp("guardfor");
		env->set("guarded/" + arg, me->query("id") );
		if (arg == old_dir)  
			message_vision( "$N���ڰ�������" + default_dirs[arg] + "�ķ������κ���ͨ�С�\n", me);
		else
		{
			message_vision( "$N��ʼ����ס��" + default_dirs[arg] + "�ķ������κ���ͨ�С�\n", me);
		}
	}

	return 1;
}

// guarding��ľ�������̫�۽��Զ�����guard��
// ����������/kungfu/condition/autosaved.c��
int help(object me)
{
	write(@TEXT
ָ���ʽ��guard [<ĳ��>|<����ĳ��>|<ĳ������>|cancel]

���ָ�����������÷�ʽ���ֱ����

guard <ĳ��>      ����<ĳ��>�����������ܵ�����ʱ�������߻��Զ�����ս��������
                  �ܹ�����˳λ�����ڱ�������ǰ�棬����ֻ�й���˳λǰ�ĸ�Ŀ��
                  �Ż��ܵ����������������������ĸ���  guard �㣬��Ͳ�����
                  ���κι�����

guard <����ĳ��>  ��ס���ڵ��ϵ�ĳ����������ֹ�������ã�ֻҪ�㻹��������䣬
                  ����û��æ�������£����˾��޷�������������������뿪���ٻ�
                  ����ֻҪ�������ڣ����Խ������ػ�֮�¡�

guard cancel      ȡ�������� guard ����

guard <ĳ������>  ��סĳ�����ڷ�ֹ�����˴���������뿪����������������������
                  �ĵ��˻���·��������¡�ֻҪ��һ�ƶ���guard ��״̬�ͻ�����

guard             �����κβ�������ʾ��Ŀǰ guard �Ķ���
TEXT
	);
	return 1;
}

