//Room: /d/dali/luyuxi.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����Ϫ�ذ�");
	set("long",@LONG
һ���Ŀ�����·��������Ϫ�ϰ���ᶫ����һ������Ϫ����
����������һ������ɽ�����������де���ľ���������Ŷ�Ϫͨ���
������ţ���ȥ��Զ�����廪¥�ˡ�
LONG);
	set("outdoors", "dalis");
	set("exits",([ /* sizeof() == 1 */
	    "east"      : __DIR__"shuangheqiao",
	    "west"      : __DIR__"gudao",
	    "south"     : "/d/wudujiao/road1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -45000);
	set("coor/y", -75000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}