// Room: /qingcheng/huyingting.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "��Ӧͤ");
	set("long", @LONG
��Ӧͤ�߾�����嶥���������ߴ������ٳ�Х�������ص���
��ɽ��Ӧ����ѩ����ڣ����̲׺����������ǣ��̵���ޡ�����ҹ
�֣���ʥ�Ƹ��ƣ���˵�����ɳ�������ʦ�����ɵƣ��������˸�̾
���ѡ�
LONG );
        set("outdoors","qingcheng");
	set("exits", ([
		"eastdown" : __DIR__"shangqing",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8090);
	set("coor/y", -880);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}