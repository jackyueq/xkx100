// /yubifeng/eastroom1.c
// Last modified by winder 2003.9.2

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @long
����ԭ�Ƕ�ׯ���ؽ��ɱ�֮������ʮ���������������ɽҰ��һ
����������Ҳ��ͽ���ı��ˡ�
long );
	set("exits", ([
		"west" : __DIR__"zoulang4",
	]));
	set("no_clean_up", 0);
	set("coor/x", 6140);
	set("coor/y", 5190);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
