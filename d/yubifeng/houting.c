// /yubifeng/houting.c
// Last modified by winder 2003.9.2

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @long
������ׯ�����÷���Ϣ�ĵط����ĽǸ�����һ���̿��һ�Ű���
�����У���Χ��ɨ�����Ǹɾ����ܼ����ں������ǷԸ���ʲô��
long );
	set("exits", ([
		"west"  : __DIR__"zoulang5",
		"east"  : __DIR__"zoulang6",
		"north" : __DIR__"houyuan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yubifeng");
	set("coor/x", 6120);
	set("coor/y", 5200);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
