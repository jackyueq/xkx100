// /guanwai/xiaotianchi.c

inherit ROOM;

void create()
{
	set("short", "С���");
	set("long", @LONG
С����ֳƳ��׾�����ԲԲ�羵����ˮ�������ֺ��ͱڵ�ӳ��䣬
���������һ������͸���ϸɳ�����ȵ����ں��ף�ǡ��չ���ŵ�һ��
��˿��̺���ഫ������Ůÿ���������ԡ��ϴ�Ͼ͵�����ķ�ߣ���
����������м�Ŀ�����ʯ�ϣ�����С��ش����ױ������������
LONG );
	set("exits", ([
		"eastup"  : __DIR__"pubu",
		"west"    : __DIR__"heifengkou",
	]));
	set("no_clean_up", 0);
	set("outdoors", "changbai");
	set("coor/x", 6180);
	set("coor/y", 5200);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}