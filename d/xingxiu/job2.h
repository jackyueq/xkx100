// Room: /d/xingxiu/job2.h
// Last Modified by winder on Apr. 25 2001

int valid_leave(object me, string dir)
{
	object ob;
	if(me->query_temp("wait_target") &&
		objectp(present("anran zi", environment(me))))
		return notify_fail("��Ȼ��������������ǰ���ȵ�������������ҹ�������\n");
	if(me->query_temp("xx_rob") &&
		objectp(ob = present("hubiao biaoshi", environment(me))) &&
		ob->query("target") == me)
		return notify_fail("������ʦ������ס���ȥ·�����������������ˣ�\n");  
	if(me->query_temp("xx_rob") && objectp(present("shangdui",environment(me))))
		return notify_fail("�̶��������أ�����(qiang)����\n");  
	return ::valid_leave(me, dir);
} 
