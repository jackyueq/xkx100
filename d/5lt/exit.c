// Room: /d/5lt/exit.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
���������ݽ��⣬��ȻԶ���سǣ�ȴû��ʲ��ɽ���ݿ��ڸ�����û��
������һ��С��ׯ�������ǹ����ճ������������Ϣ���������ٲȻ
������Դ��Ȼ�Եõ����ӡ�
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"qsroad",
		"east" : "/d/taohuacun/taohua1",
	]));
        set("objects", ([
        ]) );
//	set("no_clean_up", 0);
        set("outdoors", "5lt" );
	set("coor/x", -110);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}