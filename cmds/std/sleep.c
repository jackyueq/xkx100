// /cmds/std/sleep.c
// Dec.11 1997 by Venus
// Modified by Zeratul Jan 11 2001 ��¼�����ϴν���ʱ��
//��60��ע���ˣ�ahda
//Modified by Qingyun 2004.9.30 ����˯��ʱ�䳤�ȡ���baby�ĳ�condition����

#include <ansi.h>;
#include <command.h>;
void wakeup(object me, object where);
int wakeup2(object me,object slept,object where);
void del_sleeped(object me);

int main(object me, string arg)
{
	object obj, old_target;
	int i,sleeptime;
	object *inv;
	mapping fam;
	object where = environment(me);

	seteuid(getuid());

	if ( (!(fam = me->query("family")) ||
		fam["family_name"] != "ؤ��") &&
		!(where->query("sleep_room")) ||
		(where->query("no_sleep_room")) ||
                (where->query_temp("no_sleep")))
		return notify_fail("���ﲻ������˯�ĵط���\n");
	if( me->query_temp("no_sleep") ) return notify_fail("������˯���ž���\n");
	if( me->query_temp("noliving") ) return notify_fail("");   // �ǻ���
	if( me->is_busy()) return notify_fail("����æ���أ�\n");
	if( me->is_fighting() ) return notify_fail("ս���в���˯����\n");
	if( (fam = me->query("family")) && fam["family_name"] == "ؤ��")
	{
		inv = all_inventory(where);
		for(i=0; i<sizeof(inv); i++)
	if((living(inv[i]) || !inv[i]->query_temp("noliving")) &&
	inv[i]!=me && inv[i]->is_fighting())
			return notify_fail("���������ڴ�ܣ��㻹����˯��\n");
	}
	if (where->query("hotel") && !(me->query_temp("rent_paid")))
	{
		message_vision("��С���������$N��У������ﵱ�����������ȵ�һ¥��Ǯ������˯��\n",me);
		return 1;
	}
	//��������˯��
	if (me->query_temp("sleeped"))
		return notify_fail("���˯��һ�����Ȼ��ɡ� \n");
//���ϸ�ð����˯��
		if (me->query_condition("ill_kesou"))
				{
					tell_object(me, "��������۾��ú�˯��һ��������" +
					"����"+"������ĥ���㣬����շת���ߡ�\n");
					return 1;
				}
		if (me->query_condition("ill_shanghan"))
				{
					tell_object(me, "��������۾��ú�˯��һ��������" +
					"�˺�"+"������ĥ���㣬����շת���ߡ�\n");
					return 1;
				}
		if (me->query_condition("ill_fashao"))
				{
					tell_object(me, "��������۾��ú�˯��һ��������" +
					"����"+"������ĥ���㣬����շת���ߡ�\n");
					return 1;
				}
		if (me->query_condition("ill_dongshang"))
				{
					tell_object(me, "��������۾��ú�˯��һ��������" +
					"����"+"������ĥ���㣬����շת���ߡ�\n");
					return 1;
				}
		if (me->query_condition("ill_zhongshu"))
				{
					tell_object(me, "��������۾��ú�˯��һ��������" +
					"����������" + "������ĥ���㣬����շת���ߡ�\n");
					return 1;
				}
// ��ð���˽��� 
	if((!arg) || arg==(string)me->query("id"))
	{
		if (where->query("sleep_room"))
		{
			write("��������һ�ɣ���ʼ˯����\n");
			write("��һ�������ͽ��������硣\n");
			me->set_temp("block_msg/all",1);
			message_vision("$Nһ���������ڴ��ϣ���һ����������������������硣\n",me);
		}
		else
		{
			write("�������½���һ�ɣ���ʼ˯����\n");
			write("��һ�������ͽ��������硣\n");
			me->set_temp("block_msg/all",1);
			message_vision("$N�����½�������һ�ɣ���һ�����������������������\n",me);
		}
		where->add("no_fight", 1);
		where->add_temp("sleeping_person", 1);

		me->set("no_get", 1);
		me->set("no_get_from", 1);
		me->set_temp("sleeped",1);


		if( userp(me) ) me->set_temp("noliving/sleeped", 1);
		else me->disable_player("<˯����>");
//	call_out("wakeup", random(45-me->query("con"))+45, me, where);
		sleeptime=random(45-me->query("con"))+20;
		if (me->query("mud_age")<86400*4)//18���¼ӿ�����
			sleeptime-=20;
		if (where->query("hotel")) 
		{//��ջ˯��ʱ�����
			me->delete_temp("rent_paid");
			sleeptime=sleeptime*1/2;
		}
		if (sleeptime < 10) sleeptime=10;
//		call_out("wakeup", sleeptime, me, where);
		me->start_call_out((:call_other,__FILE__,"wakeup",me,where:),sleeptime);
		return 1;
	}
	if(!objectp(obj = present(arg, where)))
		return notify_fail("�����˭һ��˯��\n");
	if( !obj->is_character() )
		return notify_fail("���Դ���ë���ˣ�\n");
// can't sleep with npc...
	if( !userp(obj) )
		return notify_fail("�˼ҿɲ�Ը���㣡\n");
	if(me->query("gender") == "����")
		return notify_fail("����̫�డ������\n");
	if(me->query("gender") == obj->query("gender"))
		return notify_fail("���Է��������ͬ���أ�����\n");
	if( !living(obj) || obj->query_temp("noliving") )
		return notify_fail(obj->name() + "û������˯�ˡ�\n");
	if (!where->query("if_bed"))
		return notify_fail("���������̫�ðɡ�\n");
	if( (int)me->query("qi") * 100 / (int)me->query("max_qi") < 50 )
		return notify_fail("��������������������㡣\n");

	if( userp(obj) && (object)obj->query_temp("pending/sleep")!=me )
	{
		message_vision(RED"\n$N���������ض�$n˵���ң�����\n\n"NOR, me, obj);
		if( objectp(old_target = me->query_temp("pending/sleep")) &&
			!((string)old_target->query("id")==(string)obj->query("id")))
			tell_object(old_target, YEL + me->name() + "�ı����ⲻ�����˯�ˡ�\n" NOR);
		me->set_temp("pending/sleep", obj);
		tell_object(obj, YEL "����" + me->name() + "("+(string)me->query("id")+")"+ "������㣮���������Ը�⣬��Ҳ��һ�� sleep ָ�\n" NOR);
		write(YEL "�Է����ڿ����У�����\n" NOR);
		return 1;
	}
	message_vision(RED "\n$N����$n���ĵ�һЦ�����˵�ͷ��\n\n" NOR, me, obj);

	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++)
		REMOVE_CMD->do_remove(me, inv[i]);
	inv = all_inventory(obj);
	for(i=0; i<sizeof(inv); i++)
		REMOVE_CMD->do_remove(obj, inv[i]);

	if(me->query("gender")=="����")
	{
		tell_object(me, HIY"\n\n��§��"+obj->query("name")+"���������壬���ɵ��������ԣ�����\n\n\n" NOR);
		tell_object(obj, HIY"\n\n������"+me->query("name")+"�Ļ�����ɵ��������ԣ�����\n\n\n" NOR);
	}
	else
	{
		tell_object(obj, HIY"\n\n��§��"+me->query("name")+"���������壬���ɵ��������ԣ�����\n\n\n" NOR);
		tell_object(me, HIY"\n\n������"+obj->query("name")+"�Ļ�����ɵ��������ԣ�����\n\n\n" NOR);
	}
	me->set("last_slp",me->query("mud_age"));
	obj->set("last_slp",obj->query("mud_age"));
	if (me->query("couple/couple_id")==obj->query("id"))		me->set("last_sleep_couple",time());
	if (obj->query("couple/couple_id")==me->query("id"))		obj->set("last_sleep_couple",time());
	me->set_temp("block_msg/all",1);
	obj->set_temp("block_msg/all",1);
	me->delete_temp("pending/sleep");
	obj->delete_temp("pending/sleep");
	message_vision(HIY "$N��$n���뱻�У�§��һ��˯���ˣ�����\n\n\n" NOR,me,obj);
	if( userp(me) ) me->set_temp("noliving/sleeped", 1);
	else me->disable_player("<˯����>");
	if( userp(obj) ) obj->set_temp("noliving/sleeped", 1);
	else obj->disable_player("<˯����>");
// ����¼
	if (!me->query("sex/number"))
		me->set("sex/first",obj->query("id"));
	me->add("sex/number",1);
	me->add("sex/"+obj->query("id"),1);
	if (!obj->query("sex/number"))
		obj->set("sex/first",me->query("id"));
	obj->add("sex/number",1);
	obj->add("sex/"+me->query("id"),1);
// ��¼����

//	call_out("wakeup2",random(45 - me->query("con")) + 30+3, me,obj, where);
//	call_out("wakeup2",random(45 - obj->query("con")) + 30+1, obj, me,where);
  me->start_call_out((:call_other,__FILE__,"wakeup2",me,obj,where:),random(45 - me->query("con")) + 30+1);
	obj->start_call_out((:call_other,__FILE__,"wakeup2",obj,me,where:),random(45 - obj->query("con")) + 30+3);
	return 1;
}
void wakeup(object me,object where)
{
	if(!me) return;
	me->delete("no_get");
	me->delete("no_get_from");
	if (!me->query_temp("block_msg/all"))	return;// �Ѿ��ܿ��������� ������ν�ѹ���
	if ((me->query("mud_age")-me->query("last_slp"))<120 && me->query("max_jing")>160)
	{
		//��ʱ��������  �ָ�һ��ľ������ķ�һ����
		//�����̵ı�������Ҳ�ûָ�һ�� 
		me->add("qi", me->query("eff_qi")/2 - me->query("qi")/2 );
		me->add("jing", me->query("eff_jing")/2 - me->query("jing")/2 );
		if (me->query("neili") < me->query("max_neili"))
			me->add("neili", me->query("max_neili")/4 - me->query("neili")/4 );
		me->add("tili", me->query("max_tili")/2 - me->query("tili")/2 );
		message_vision("$N���Ժ����������۾�����ɢ���������������\n",me);
		me->set_temp("block_msg/all", 0);
		tell_object(me, "��һ������������˯��̫�࣬����û�лָ����١�\n");
	}
	else
	{
		me->set("qi", me->query("eff_qi"));
		me->set("jing", me->query("eff_jing"));
//		if (me->query("neili") < me->query("max_neili"))
		me->add("neili", me->query("max_neili")/2 - me->query("neili")/2 );
		me->set("tili", me->query("max_tili") );
		me->set("last_slp",me->query("mud_age"));//��¼���һ����ȫ˯�ߵ�ʱ��
		message_vision("$Nһ����������������ػ��һ�½�ǡ�\n",me);
		me->set_temp("block_msg/all", 0);
		tell_object(me, "��һ��������ֻ���������档�ûһ���ˡ�\n");
	}

	if( userp(me)) me->delete_temp("noliving");
	else me->enable_player();

//	remove_call_out("del_sleeped");

//	call_out("del_sleeped", 1, me);//����˯���������������� ��������1s
	me->start_call_out((:call_other,__FILE__,"del_sleeped",me:),1);

	if (where->query("no_fight") >= 2)
		where->add("no_fight", -1);
	else
		if ((!where->query("sleep_room") && !where->query("hotel")) ||
			where->query("no_fight")==1 )
			where->delete("no_fight");

	where->add_temp("sleeping_person", -1);
	return;
}

int wakeup2(object me,object slept,object where)
{
	int qi_cost;
	object obj;

	me->set("qi", me->query("eff_qi"));
	me->set("jing", me->query("eff_jing"));
	me->add("neili", me->query("max_neili")/2 - me->query("neili")/2 );
	if( userp(me)) me->delete_temp("noliving");
	else me->enable_player();

	qi_cost=50+5*((int)me->query("str")-(int)me->query("con"));
	if(qi_cost>(int)me->query("max_qi")/2)
		qi_cost=(int)me->query("max_qi")/2+1;
	me->add("qi", -qi_cost);
	if (me->query("qi") <= 0) me->set("qi", 10);

	while( environment(me)->is_character() )
	me->move(environment(environment(me)));

	if(me->query("gender")!="Ů��")
	{
		message_vision(HIY"$N���˹������ƺ����������Ҹ�֮�С�\n"NOR,me);
		me->set_temp("block_msg/all", 0);
		tell_object(me, "�����˹������ƺ����������Ҹ�֮�С�\n");
		return 1;
	}
	else
	{
		message_vision(HIY"$N���˹��������ϻ��������۵�Ц�ݡ�\n"NOR,me);
		me->set_temp("block_msg/all", 0);
		tell_object(me, "�����˹��������ϻ��������۵�Ц�ݡ�\n");
		obj=slept;

		if((int)(me->query("mud_age")/86400) < 4 ||
			(int)(me->query("mud_age")/864000) < me->query("child") ||
			(int)(me->query("mud_age")/86400) > 36  
			)
			return 1;

		if (me->query_condition("huaiyun"))	return 1;			

		if (!me->query("child") || random(me->query("sex/"+slept->query("id"))) > me->query("age")/2*me->query("child"))
			{
				if(me->query_temp("no_huaiyun")) // �Ժ����Ӻ������Ӧ��obj
				{
					message_vision(HIY "\n$N��������һ�����������������ƽ��������\n"NOR,me);
					return 1;
				}
//				tell_object(me,"���Ȼ�о��е�ͷ�Σ����������ָֻ��˹�����\n");
				me->set("baby/father",slept->query("id"));
				me->set("baby/gender",random(2)+1);
				me->apply_condition("huaiyun",3200); //һ����Լ 320 heart beat 
			}
			return 3;
	}
}

void del_sleeped(object me)
{
	if (objectp(me) && me->query_temp("sleeped"))
		me->delete_temp("sleeped");
}
int help(object me)
{
	write(@HELP
ָ���ʽ : sleep <����>
 
    ����˼�壬���ָ��������˯���ġ��ָ�����������Ч;������˯
��ʱ�Ǳ����۵ģ�����.......ҪС��Ŷ��

    �������ż˯�Ļ������л�������С���ˡ�:)
HELP
	);
	return 1;
}