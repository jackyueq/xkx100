//Room: /d/dali/xiaguan.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�¹س�");
	set("long",@LONG
�¹سǣ�������β�ǣ�Ϊ���޷��������ƴ��Ѽ����١������ӱ�
��ɽ��´�����ˮ�Ƴ��϶������˵ķ羰�续����ȥ�ϱ߲�Զ����
����ǣ�������̫�ͳǣ����е�·ͨ���������˸������������ġ�̨
��Ϊ����Ҳ���������ġ�
LONG);
	set("objects", ([
	   __DIR__"npc/tshangfan": 1,
	   __DIR__"npc/wshangfan": 1,
	]));
	set("outdoors", "dalin");
	set("exits",([ /* sizeof() == 1 */
	    "northeast"  : __DIR__"cangshan",
	    "northwest"  : __DIR__"cangshanzhong",
	    "south"      : __DIR__"ershuiqiao",
	]));
	set("coor/x", -41000);
	set("coor/y", -57000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}