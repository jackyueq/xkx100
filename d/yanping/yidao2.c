// Room: /d/yanping/yidao2.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
�Թ������޳�;����������ȫ��������������������������ͨ��
������ؽ�ϪϪ�����£�����һ���������ƶ��ϣ���ǰ�ֺ����ˣ�Զ��
�������֣���һ��������ڡ�վ��ɽ�����ڣ�Զ����ƽ���У�˫Ϫ����
ֱ������һ�㡣
LONG );
	set("exits", ([
		"northdown" : __DIR__"yidao1",
		"southup"   : __DIR__"gubao",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yanping");
	set("coor/x", 1500);
	set("coor/y", -6100);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
