// /d/beihai/yuexin.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "���ĵ�");
	set("long", @LONG
��������������֮���ĵ����Ϊ�忪�䡢��ɽ���߶����������
��������֮�������ڷǳ�������ֻ��ϡ������ɮ��ɨ����Ҷ����������
ǰ�п�������̨��������¥��������Ժ����һ��������֦Ҷï�ܡ�����
���ߺܰ������������Щʲô��
LONG
	);
	set("exits", ([
		"east"    : __DIR__"yongansi",
		"northup" : __DIR__"qingxiao",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -200);
	set("coor/y", 4080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
