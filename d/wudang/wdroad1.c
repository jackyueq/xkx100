// wdroad1.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ�������������
�Ҷ��������������һЩС��̯���ƺ���һ�����С�����ͨ�����ݳǡ�
������һ��Ƭ���֡�
LONG );
	set("outdoors", "sanbuguan");
	set("exits", ([
		"south"     : __DIR__"wdroad2",
		"north"     : "/d/city/dujiangqiao",
	]));
        set("no_clean_up", 0);
	set("coor/x", 10);
	set("coor/y", -120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
