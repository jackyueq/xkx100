//Room: /d/dali/gaolishan2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����ɽ����");
	set("long",@LONG
����ɽ�ϵ����ն�����������������������̡��ش���ɽ��
���Ժ����ܻ�������ʱ����û��ֻ���¸ҵ����˲Ÿ���������������
��ɽ������ˮ�ȵء�
LONG);
	set("objects", ([
	   "/d/hangzhou/npc/laohu": 1,
	]));
	set("outdoors", "daliw");
	set("exits",([ /* sizeof() == 1 */
	    "east"  : __DIR__"gaolishan1",
	]));
	set("coor/x", -90020);
	set("coor/y", -70020);
	set("coor/z", 20);
	setup();
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
	{
		me->set_temp("dali_xc/gls",1);
	}
}