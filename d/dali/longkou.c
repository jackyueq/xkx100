//Room: /d/dali/longkou.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","���ڳ�");
	set("long",@LONG
�����ѵ������Ͻ��ˣ����ڳ�����Ԫ�������ٽ�·��������ϲ�
�����ǧ�����������ϡ�٣��˵�����������Ĳ�Զ��ȴҲ����
������Ҫ�ؿ�֮һ�ˣ��Ǻ��Ϸ��ٹ�ͨ�̵Ŀڰ����ɴ˱�ȥ��ʮ����
����ϲ�ݳǣ��ϱ���Ԫ���в���̨�Ĵ�ׯ������ٸ��ڴ���Щפ����
LONG);
	set("objects", ([
	   __DIR__"npc/bing": 2,
	]));
	set("outdoors", "dalis");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : __DIR__"feilihueast",
	]));
	set("coor/x", -39000);
	set("coor/y", -89200);
	set("coor/z", 0);
	setup();
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
	{
		me->set_temp("dali_xc/lk",1);
	}
}