// Room: /d/xiangyang/northjie.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ�ֵ������ϱ���ͷ���졣����������
���ţ��ϱ��Եúܷ�æ��������һ��ݣ�һ�����顰�衱����
��ڷ��������ҡҷ�ţ�һ�ɹɲ������������������������
�ı���Ӫ���������������洫���Ĳ�������
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : __DIR__"chaguan",
		"south" : __DIR__"dingzi",
		"west"  : __DIR__"bingying1",
		"north" : __DIR__"northgate1",
	]));
	set("coor/x", -510);
	set("coor/y", -460);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}