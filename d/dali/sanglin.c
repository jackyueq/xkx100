//Room: /d/dali/sanglin.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ɣ��");
	set("long",@LONG
һ��Ƭɣ���������ڵ�ɽ�Ļ���ɽ���ϡ����ϡ���˿�ǰ������
��Ҫ��ҵ�����ĸ�Ů����֯˿����֯�Լ����ŵĶ�ȹ��Ҳ��������
�����佻��Щ������Ʒ��һȺ���Ĺ��������ּ�æ�Ų�ժɣҶ��
LONG);
	set("objects", ([
	   __DIR__"npc/caisangnu": 1,
	]));
	set("outdoors", "dalie");
	set("exits",([ /* sizeof() == 1 */
	    "northdown"  : __DIR__"yangzong",
	]));
	set("coor/x", -30960);
	set("coor/y", -70620);
	set("coor/z", 30);
	setup();
}
void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
	{
		me->set_temp("dali_xc/sl",1);
	}
}