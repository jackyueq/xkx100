// /guanwai/laolongtou.c
inherit ROOM;

void create()
{
	set("short", "����ͷ");
	set("long", @LONG
����ͷ�����ﳤ����ˡ��κ�¥Ρ��߾��ͷ�ϣ�¥�ϡ��۽���
��ĺ��ҾӸ����£�ֱ���󺣡��Գκ�¥����һʯ���𼶶��������
����վ��ʯ���ն�¥ƽ̨������������һɫ���ޱ��޼ʣ�������ǧ��
LONG );
	set("exits", ([
		"northwest" : __DIR__"shanhaiguan",
		"southwest" : "/d/beijing/road3",
	]));
	set("objects",([
		__DIR__"npc/fengxifan" : 1,
	]));
//	set("no_clean_up", 0);
 	set("outdoors", "guanwai");
	set("coor/x", 5100);
	set("coor/y", 4500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
