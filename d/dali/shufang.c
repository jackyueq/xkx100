//Room: /d/dali/shufang.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short", "�鷿");
	set("long", @LONG
���Ǵ�������������鷿����������һ����ľ�����Ϸ��Ų����飬
��ǽ�ĵط�����һ����ܣ����������������￴�顣
LONG);
	set("exits",([ /* sizeof() == 1 */
	    "west"  : __DIR__"tingfang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -38970);
	set("coor/y", -69990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}