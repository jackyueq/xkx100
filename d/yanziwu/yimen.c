//ROOM: /d/yanziwu/yimen.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long",@LONG
һ������ĵ񻨴��ţ�һ����Ŀ�����ӹ������ϣ����Ժ�ɫС׭д
�� "����" ���֣�����һ��ׯ������ĸо����������������������Ϣ
�ĵط�����������Ľ�ݼ����÷����Ŵ����
LONG );
	set("exits", ([
		"west"  : __DIR__"qinfang1",
		"east"  : __DIR__"dannuo",
		"north" : __DIR__"longfeng",
		"south" : __DIR__"canheju",
	]));
	set("no_clean_up", 0);
	set("coor/x", 820);
	set("coor/y", -1530);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}