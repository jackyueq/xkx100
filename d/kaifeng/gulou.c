// /kaifeng/gulou.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "��¥");
	set("long", @LONG
һ��ľ�ṹ��Сͤ��¥���ϲ���˸���ģ���������ÿ�쳿��ĺ��
ʱ���á���һ��С¥��ͨ���²㡣��¥���Ľǹ�����������ҡ�ţ�
���⶯����
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"west" : __DIR__"qianyuan",
	]));

	setup();
	replace_program(ROOM);
}
