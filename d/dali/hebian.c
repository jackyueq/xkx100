//Room: /d/dali/hebian.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�ӱ�");
	set("long",@LONG
�������ӱߣ�����ɽ�ڼ�����ֱ��ֱ�£�������һ������Ա���
���������ڴ����򶫱��ڶ�ȥ����ˮ��ӿ���������죬����һ����
�˵ĺ��졣�˴��ӹ���խ��ǰ������������������һ�ô����ϣ���һ
�˿�Ӷ������ƿ���Ԯ��������ȥ�������ǳ�ɽ���롣
LONG);
	set("objects", ([
	   __DIR__"npc/wshangfan": 1,
	]));
	set("outdoors", "daliw");
	set("exits",([ /* sizeof() == 1 */
	    "southup"   : __DIR__"shanlin",
	    "east"      : __DIR__"heshang",
	]));
	set("coor/x", -90000);
	set("coor/y", -57000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}