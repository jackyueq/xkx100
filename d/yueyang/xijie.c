// Room: /d/yueyang/xijie.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ���ֳ��ֿ����ʯ�������ƥ�۹����õ��������е�����һ
Щϡϡ����������£�������������Щ�����������ˡ�����Ϊ����ؤ��
�ܶ�ĳ�פ�أ����������������ģ���ؤ��Ⱥ�������������صĿ���Ҳ
�����˲�
    �����Ǹ��㳡��������һ�����ݡ�
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"zhongxin",
		"west"  : __DIR__"ximen",
		"south" : __DIR__"guangchang",
		"north" : __DIR__"gaibanggate",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/chen-guyan" : 1,
		CLASS_D("gaibang")+"/bangzhong" : 1,
	]));
	set("coor/x", -1420);
	set("coor/y", -2270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
