// Room: /d/nanyang/jiulou2.c
// Last Modified by winder on Nov. 20 2001

inherit ROOM;

void create()
{
	set("name", "ӭ��¥");
	set("short", "ӭ��¥��¥");
	set("long", @LONG
����������������ѧʿ������������ʫ��������������Ҳ������
�߳Ժȱ������ס�����Ҳ�ǳ���ٰ�ϲ�����ѳ�������վ��¥����
����ֻ�����Ŀ�������������һ�غ�ˮ���̲������������ǳ�ɽ���롣
ǽ�Ϲ��ż۸�����(paizi)��
LONG );
	set("item_desc", ([
		"paizi" : "����ר���ϵ����롣\n",
	]));
	set("exits", ([
		"down" : __DIR__"jiulou1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 500);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
