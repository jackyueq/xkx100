// Room: /d/yanziwu/langfang.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������������˽���һ��������ɽׯ�������񶴡������ղ��ŵ�
����ң�Ӻ�����ʦ������ˮ�ղص������¸��Ÿ��ɵ��书�ؼ�����ң��
�����ɱ�ʣ���ˮ����Զ�����ĺ���Щ�伮�����ǵ�Ů��������ɽׯ
ׯ��������ɽ������ǧ�������˵ֹ��գ��Ͳ������ɽ��֮�С�����
�촰һ�����촰��һ��������������ж�����ܣ����ϰ�������ɫ�ž�
���鼮�����Ͼ����б�ǩ(sign)��
LONG );
	set("exits", ([
		"out"    : __DIR__"dong8",
	]));
	set("item_desc", ([
		"sign" : "ǩ�ϱ������֡��䵱����ǡ���������ɵ����ơ�\n" 
	]));
	set("objects", ([
		__DIR__"book/axe_book" : random(2),
		__DIR__"book/club_book" : random(2),
		__DIR__"book/hook_book" : random(2),
		__DIR__"book/whip_book" : random(2),
		__DIR__"book/staff_book" : random(2),
		__DIR__"book/stick_book" : random(2),
		__DIR__"book/spear_book" : random(2),
		__DIR__"book/sword_book" : random(2),
		__DIR__"book/blade_book" : random(2),
		__DIR__"book/hammer_book" : random(2),
		__DIR__"book/dagger_book" : random(2),
		__DIR__"book/throwing_book" : random(2),
	]));
	set("coor/x", 1190);
	set("coor/y", -1270);
	set("coor/z", -2);
	setup();
	replace_program(ROOM);
}

