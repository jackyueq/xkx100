// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
        set("short", "����");
	set("long", @LONG
������һ�������������ϣ������������������������������
�䣬�����泩���������и������������Ǻ�Ժ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ 
            "southeast" : __DIR__"houyuan",
            "northeast" : __DIR__"zoulang4",
            "south"     : __DIR__"zoulang2",
            "west"      : __DIR__"chufang",
	]));
	set("coor/x", 1600);
	set("coor/y", -1920);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}