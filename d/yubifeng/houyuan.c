// /yubifeng/baozang.c
// Last modified by winder 2003.9.2

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @long
����ׯ��ƽʱ�����ĵط�������������壬������ݲ�����ֻ�м�
�ò���ͦ�������Ժ����һ��ʯ���ͼ���ʯ�ʡ�
long );
	set("exits", ([
		"south" : __DIR__"houting",
	]));
	set("no_clean_up", 0);
	set("coor/x", 6120);
	set("coor/y", 5210);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
