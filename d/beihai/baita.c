// /d/beihai/baita.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����Ϊ������Ϊ������ɵ����澰�۵����ġ�λ�ڱ�������֮
�ۡ�������Ϊ����������Ϊ�ߴ��שʯ̨��������Ϊ�۽�ʽ����������
�ϳ��и���ʽ�����������к���ʽ�۹��ţ����ڿ��в����������
�ϲ�Ϊϸ����ʮ���죬��Ϊ����ͭ��ɡ�ǣ���Ե��ͭ��ʮ�ĸ�������Ϊ
�̽���汦����ɲ��
LONG
	);
	set("exits", ([
		"northdown" : __DIR__"yilan",
		"southdown" : __DIR__"yongansi",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);
	set("coor/x", -190);
	set("coor/y", 4090);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
