//Edited by fandog, 02/16/2000

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
���Ǿ��ݳǶ���һ��С�֡���Ȼ����û�����ַ���������ȴҲ����
Щ����������ȥ�Ҵҡ�������һ��Ƨ����С�����ȴ��һ��׳�۵�¥
��
LONG
	);
	set("outdoors", "jiangling");
	set("exits", ([
		"east"  : __DIR__"yuanmiaoguan",
		"south" : __DIR__"dongjie2",
		"west"  : __DIR__"xiang1",
	]));

	set("no_clean_up", 0);
	set("coor/x", -1470);
	set("coor/y", -2020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}