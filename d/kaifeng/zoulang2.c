// /kaifeng/zoulang2.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������̵�һ�����ȣ�����ĵذ��뿪�������ߣ���ϴ�úܸɾ���
ÿ��һ�ε��ȼ��϶��ο��˾��µķ������������жϣ������ȥ����
��԰���ϱߵĿյ���Ҳ���˼��òˡ������Ǹ�С�񷿡�
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"west" : __DIR__"zoulang1",
		"east" : __DIR__"caidi1",
		"south" : __DIR__"caidi2",
		"north" : __DIR__"caifang",
	]));
	set("outdoors", "xiangguosi");

	setup();
	replace_program(ROOM);
}
