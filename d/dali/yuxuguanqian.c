//Room: /d/dali/yuxuguanqian.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�����ǰ");
	set("long",@LONG
����һ����ۣ���ǰ����д�š�����ۡ��������֣�����һ��
��ˮ������С����������������ʵ���������Եĺõط���
LONG);
	set("objects", ([
	   __DIR__"npc/xiaodaogu": 2,
	]));
	set("outdoors", "dalic");
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"yuxuguan",
	    "south"  : __DIR__"hudiequan",
	]));
	set("coor/x", -39000);
	set("coor/y", -68990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}