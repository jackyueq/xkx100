// piao.c

#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	mapping fam;
	object obj, old_target, where = environment(me);
	int oexp,mexp;
	seteuid(getuid());

	if (me->query("gender") =="Ů��")
		return notify_fail("Ů���������µ�Ȼ̫���ˡ�\n");

	if (!environment(me)->query("piao_room"))
		return notify_fail("����潵�ȻҪȥ��Ժ�ˣ�\n");
	if (!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("�����ںܳ嶯�����ǹ����Ƕ����ڣ�\n");
	if (me->query("gender") =="����")
		return notify_fail("�����Ǹ����ⶼû�У�����Ӳ�Ϲ���\n");
	if (me->query("age") < 17)
		return notify_fail("С�ֵܣ�Ҫ�ҹ�������������ɣ�\n");
	if (obj->query("age") < 17)
		return notify_fail("�˼�С���ﻹû��ʮ�����أ�\n");
	if(query_ip_name(obj)==query_ip_name(me))
		return notify_fail("���Լ���û��˵�����������\n");
	if (obj==me) return notify_fail("�Լ���ο�Լ�����Ҫ��ô�鷳���\n");
	if (!obj->is_character())
		return notify_fail("�ۣ����Ķ��������Ź���\n");
	if (!living(obj) || obj->query_temp("noliving") )
		return notify_fail(obj->name() + "���������ˡ�\n");
	if (!wizardp(me) && wizardp(obj) )
		return notify_fail("��ʦ���������µġ�\n");
	if (obj->query("eff_jing")<20)
		return notify_fail("�������İɣ����ٱ���������ģ�\n");
	if (obj->query_condition("prostitute") < 1)
		return notify_fail("�����Ǽ�Ů����\n");
	tell_object(me,"��������������" + obj->name() + "�������������ѳ�ȥ" + obj->query("name") + "���·���\n\n");
	tell_object(obj,me->name()+"һ�����Ķ��ŵ�ģ���߹�����һ�����������¶��һ���Ｑ�������־�������·���\n\n");
	message("vision","ֻ��" + me->name() + "һ�����Ķ��ŵ�ģ������"+obj->name() + "\nȻ��Ｑ�Ｑ��������ȥ"+obj->name()+"���·���\n\n\n", environment(me), ({ me,obj }) );
	me->start_busy(3);
	message_vision("��һ��������޵�ҹ��$N��$n˫˫�ɾ�һ��¶ˮԧ�졣\n",obj,me);
	message_vision("$N��$nΪ����Ľ����ͷ��������˲���ĥ��Ĺ��ס�\n",obj,me);
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
	me->receive_damage("jing", 3);
	me->receive_wound("jing", 3);
	me->add("mud_age", 240);
	me->add("combat_exp",2);
	me->add("shen",-1000);
	me->set("couple/have_couple",1);
	me->start_busy(3);
	obj->receive_damage("jing",1);
	obj->receive_wound("jing", 20);
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : piao <ĳ��>

    �Ρ�����Ժר�����

HELP
	);
	return 1;
}

