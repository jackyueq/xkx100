inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�����Ƕ������֣������Ľֵ��ϳ�ˮ���������������������߾���
�찲���ˡ������Ǿ����������ġ�����Ժ��������Թ󡢹�͢��������
ȥ��
LONG );
	set("no_sleep_room",1);
	set("outdoors", "beijing");
	set("exits", ([
		"east" : __DIR__"dongcha2",
		"west" : __DIR__"tian_anm",
		"north" : __DIR__"yihongyu",
		"south" : __DIR__"fuweibiaoju",
	]));
	set("objects", ([
		CLASS_D("heimuya")+"/qin" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -190);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
