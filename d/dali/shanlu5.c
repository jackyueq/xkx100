//Room: /d/dali/shanlu5.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ɽ·");
	set("long",@LONG
һ��ɽ·��������ï�ܵ����֣����������಻���Ĵ�ɽ����·��
�Լ��ɼ�һЩ����Ĵ���ɽ·���������š�
LONG);
	set("outdoors", "dalis");
	set("exits",([ /* sizeof() == 1 */
	    "southeast"  : __DIR__"shanlu4",
	    "north"      : __DIR__"shanlu6",
	]));
	set("objects", ([
	   __DIR__"npc/wuliangdizi": 1,
	]));
	set("coor/x", -65000);
	set("coor/y", -78000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}