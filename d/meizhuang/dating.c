// /d/meizhuang/dating.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
���Ѿ�����÷ׯ�Ĵ����ſڣ����ڵ��Ҷ�(bian)���ɷ����д�š�
������硱�ĸ����֣��ʷ�������͸��ͦ�Σ���ʧΪһ�ʺ��֡�͸����
�ţ��㿴������һ����Ⱦ��һ��ʯ���ͼ���ʯ�ʶ����ŵ��������롣��
������һ�������ã��������һ�����˵ı��棬ī�����죬�����۽���
��������ǣ����������������ī�����֣��ʷ�ɭ�ϣ�һ�ʱʱ��糤��
�Ĵ̻���
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
		"bian" : "������Ѿ��ܳ¾��ˣ�������ҡҡ�λεģ��ƺ������ʵ��\n",
	]));
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"keting",
		"south" : __DIR__"tianjing",
	]));
	set("no_clean_up", 0);

	set("coor/x", 3500);
	set("coor/y", -1420);
	set("coor/z", 10);
	setup();
	"/clone/board/meizhuang_b"->foo();
}
