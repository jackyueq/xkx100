// Room: /d/huanggong/wuying.c

inherit ROOM;

void create()
{
	set("short", "��Ӣ��");
	set("long", @LONG
������Ӣ��, ������е��Ǹ�ʽ��������������. ԭ�������ǻʵ�
ի��֮��. �������������������µ���촦, ���ڴ��������鴦, ��
�ɺ����峼У���鼮. �˴����������"���"��.
LONG
	);
	set("exits", ([
		"east"      : __DIR__"guangchang",
		"west"      : __DIR__"xihuamen",
		"south"     : __DIR__"nanxundian",
		"north"     : __DIR__"neiwufu",
	]));
	set("no_clean_up", 0);
	set("coor/x", -220);
	set("coor/y", 5260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}