inherit ROOM;

void create()
{
	set("name", "ȫ�۵¾�¥");
	set("short", "ȫ�۵¾�¥��¥");
	set("long", @LONG
����������������ѧʿ������������ʫ��������������Ҳ������
�߳Ժȱ������ס�����Ҳ�ǳ���ٰ�ϲ�����ѳ�����ǽ�Ϲ��ż۸�
����(paizi)����վ��¥���������ǣ�ֻ�����Ŀ�������
LONG );
	set("item_desc", ([
		"paizi" : "������ۿ�Ѽ���ϵȻ���ơ�\n",
	]));
	set("exits", ([
		"down" : __DIR__"jiulou1",
	]));
	set("objects", ([
		__DIR__"npc/cheng":1,
	]));
	set("coor/x", -190);
	set("coor/y", 4060);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
