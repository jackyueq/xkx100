// Room: /d/qilian/yumenguan.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "���Ź�");
	set("long", @LONG
���Ǵ�����������һ���ذ��������������ѷ��������ˡ���������
�أ�������������ľ����Ϊ���۵ĺ��ˣ���Ȱ������һ���ƣ�����
�����޹��ˡ���������ȥ���˾Ͳ����ˡ�
LONG );
	set("outdoors", "qilian");
	set("no_clean_up", 0);
	set("exits", ([
		"south"  : __DIR__"danshan",
		"east"   : __DIR__"halahu",
	]));
	set("coor/x", -20000);
	set("coor/y", 2000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}