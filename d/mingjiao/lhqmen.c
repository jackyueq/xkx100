//lhqmen.c

inherit ROOM;

void create()
{
	set("short", "�һ������");
	set("long", @LONG
�����������һ���Ĵ��ţ�ׯ�Ϲ��ӣ���ǰ�Բ������������졣
��ɫ�Ŷ����ڻ�������ϣ����⾫��Ҳ��ͨ�������ܶ�ıؾ�֮�ء�
������������Ҳ�ر�ࡣ
LONG );
	set("exits", ([
		"enter"     : __DIR__"lhqyuan",
		"southdown" : __DIR__"lhqpaifang",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	set("coor/x", -52030);
	set("coor/y", 840);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}