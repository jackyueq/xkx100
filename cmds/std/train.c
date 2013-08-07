// Filename : /cmds/std/train.c
// Last Modified by winder on Aug. 5 2001

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob,where;
	mapping fam;
	int sp, dp;
	int i, cost, train_level;

	seteuid(getuid());

//	if( me->is_fighting() )
//		return notify_fail("һ�ߴ��һ��ѱ�ޣ������ǻ����ˣ�\n");
	if ( me->query_skill("training",1) < 10 )
		return notify_fail("���Ԧ�����������죬�޷�ѵ��Ұ�ޣ�\n");
	if ( !arg )
		return notify_fail("��Ҫѵ��ʲôҰ�ޣ�\n");
	if( !objectp(ob = present(arg, environment(me)) ))
		return notify_fail("����û����ֻҰ�ްɣ�\n");
	if (userp(ob)) 
		return notify_fail("�˼�Ҳ����ң����ʲô�㰡��\n");
	if (ob->query("owner")) 
		return notify_fail("���ǳ����û�¸ɲ�ʲô�İ���\n");
	if (ob->query("race") == "����") 
		return notify_fail("�ⲻ��Ұ�ޣ�����ͷ�˰ɣ�\n");
	if (ob->query("no_train") ) 
		return notify_fail("�ⶫ��Ұ����ѱ���������˰ɡ�\n");
//	if( ob->is_fighting() )
//		return notify_fail(ob->name() + "���ڴ�ܣ�û�����㣡\n");
	if( ob->query_temp("owner") &&
		( ob->query_temp("owner") == me->query("id") ))
		return notify_fail(ob->name() + "������ѱ�����ģ��㻹���ڸ�ɶ�����أ�\n");
	if( ob->query_temp("owner") &&
		( ob->query_temp("owner") != me->query("id") ))
		return notify_fail(ob->name() + "�类�˼�ѱ���ˣ��㻹���ڸ�ɶ�����أ�\n");
	if ( ob == me )
		return notify_fail("��û��ô���ɣ����Լ������ˣ�\n");
	if (!living(ob)) 
		return notify_fail("��ֻҰ���ε��ˣ�������ѱ�������أ�\n");

	cost = me->query("max_jing")/(me->query_skill("training",1)/10) - 10;

	if ( me->query("jing") <= cost )
		return notify_fail("������̫���ˣ��޷�ѱ��Ұ�ޡ�\n");

	message_vision("ֻ��$N����"+ob->name()+"�ֽ��Ұڣ������ƶ�������ϸ�\n\n",me);

	sp = me->query_skill("training",1) + me->query("int");
	dp = ob->query("combat_exp")/100;
	
	if ( random(sp) < random(dp)/2 )
	{
		ob->kill_ob(me);
		return notify_fail("��Ԧ�����������Ƕ���Ұ�Բ�����������ʹ��˹�����\n");
	}

	me->receive_damage("jing", cost );
	message_vision("��ʱ"+ob->name()+"����$Nҡ��ҡβ�ͣ�����ѱ�����ӡ�\n\n",me);

	train_level = me->query_skill("training", 1);
	if ( (int)me->query("combat_exp") > (train_level*train_level*train_level)/10)
	{
		me->improve_skill("training", random(me->query("int")));
	}

	ob->set("attitude", "peace");
	ob->remove_all_enemy();
	ob->set_temp("owner",me->query("id"));
	ob->set_temp("ownername",me->query("name"));
	if( (strsrch(ob->query("name"), "��") >= 0) ||
		( strsrch(ob->query("name"), "¿") >= 0) ||
		( strsrch(ob->query("name"), "��") >= 0) ||
		( strsrch(ob->query("name"), "��") >= 0) ||
		( strsrch(ob->query("name"), "ţ") >= 0) ||
		( strsrch(ob->query("name"), "��") >= 0) ||
		( strsrch(ob->query("name"), "ʨ") >= 0) ||
		( strsrch(ob->query("name"), "��") >= 0) ||
		( strsrch(ob->query("name"), "��") >= 0) ||
		( strsrch(ob->query("name"), "¹") >= 0) ||
		( strsrch(ob->query("name"), "��") >= 0) ||
		( strsrch(ob->query("name"), "��") >= 0))
		ob->set("ridable",1);
	me->remove_all_enemy();
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : train <����>

    ��ָ�������ѱ��ĳ���

    �����Ѿ�ѱ���Ķ�����Խ�������ָ�

����ָ�
        come <������>:                  �ö�����������ж���
        stay:                           ֹͣ����ĸ���״̬��
        attack <ĳ��>:                  �ö��﹥�����ˡ�
        stop <������>:                  �ö���ֹͣ���˵Ĺ�����
        release:                        ������ū״̬����������롣

����ָ���ֻ��ĳЩ�������ã�
        ride <������>:                  ���������������ȡ�
        unride <������>:                �£��뿪���
        feed <����> to <������>:        �涯��ιʳ��
        imbibe <������>:                ��������ˮ��

HELP
	);
	return 1;
}

