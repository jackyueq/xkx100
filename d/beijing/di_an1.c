inherit ROOM;

void create()
{
	set("short", "�ذ��Ŷ����");
	set("long", @LONG
����һ����������Ĵ��������ͨ���ذ��š�����ͨ������������
�߾��Ƕ����ˣ�һ���˶��������Ƕ�ȥ��
LONG );
        set("outdoors", "beijing");

	set("exits", ([
		"east" : __DIR__"wangfu3",
		"west" : __DIR__"di_an2",
		"south" : __DIR__"dongchangdamen",
	]));
	set("no_clean_up", 0);
	set("coor/x", -190);
	set("coor/y", 4070);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
