//Room: /d/dali/shanlu4.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ɽ·");
	set("long",@LONG
һ��ɽ·��������ï�ܵ����֣����������಻���Ĵ�ɽ����·��
�Լ��ɼ�һЩ����Ĵ���ɽ·�������š�
LONG);
	set("objects", ([
	   __DIR__"npc/shennongdizi": 1,
	]));
	set("outdoors", "dalis");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : __DIR__"shanlu2",
	    "northwest"  : __DIR__"shanlu5",
	    "westup"     : "/d/wuliang/shanlu1",
	]));
	set("coor/x", -60000);
	set("coor/y", -80000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}