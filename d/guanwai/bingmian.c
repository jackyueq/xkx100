// /guanwai/bingmian.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������ɻ����Ľ��棬���Ѷ����˼��ߺ�ļ�������˻���ƥ����
�����ɺ��⽭�������Σ�ա����������к��Ļ�ѩ������������һƬ��
ֻ���м侭������֮����¶��һ����ɫ�ı�·��
LONG );
	set("exits", ([
		"east"  : __DIR__"damenkan",
		"west"  : __DIR__"chuanchang",
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	set("coor/x", 6090);
	set("coor/y", 5230);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}