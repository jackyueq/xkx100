// Room: /d/taishan/wudafu.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��ʷ�ǡ��أ���ʼ�ʷ�̩ɽʱ��;���꣬���ڴ˼�����£������
Ϊ�����򡱡����Ϊ���ꡣ����������䣬���ɱ��������١���Ӻ��
����ղ���������̩ɽʱ����ֲ�����ɡ�����ȭ����׾���Ծ���
�����Թű���Ϊ������ͦ�㡱����Ϊ̩���˾�֮һ��
��������������סɽ�����������ɣ���֦�´����ƹ����������ͣ���
��ӭ���ɡ�
LONG );
	set("exits", ([
		"northwest" : __DIR__"chaoyang",
		"eastdown"  : __DIR__"sandengya",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 370);
	set("coor/y", 680);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}
