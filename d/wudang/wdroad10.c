// wdroad10.c ����·
// Date: Feb.12 1998 By Java

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
������һ����������Ļ���·�ϣ���������ɭɭ�����֡������Ǻ�
�����磬��˵���������˳�û�����ɾ������ϱ�һ��С����ͨ��������
����
LONG );
	set("outdoors", "sanbuguan");
	set("exits", ([
                "north"    : __DIR__"wdroad9",
                "southup"  : __DIR__"tufeiwo1",
                "west"     : __DIR__"slxl1",
        ]));
	set("objects", ([
		__DIR__"npc/xiao_louluo":1,
	]));
	set("coor/x", -2000);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
