// Room: /yixing/nanxun.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���ݸ������ķ���ʢ��������ʿ��������ʱ���й��ַ�Ϊƽ��ȥ��
��������Լ��Ԫ���黭���鼫Ʒ�������׶��Ǻ������ϡ��������Բ���
����������֮�ʣ�����֮ī������ֽ֮�������Ϫ֮�⣬�ķ��ı�����
�³�������������Ǻ��ݸ���һ����ȴ��Ѱ�����ػ������ϸ�����
�࣬�����ĸ��Ҵ���֮����һ����ׯ��
LONG );
	set("outdoors", "yixing");
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"yixing",
	]));
	set("coor/x", 100);
	set("coor/y", -200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
