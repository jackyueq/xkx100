// Room: /d/yanziwu/juanxin.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
����ͤ��������ɽ�����¡����Ϸ���ֱָ�������ף�������������
�˻�Ȼ��ȴ������ķ��ա����ﳣ�������������㻳��ͤ��ʯ���Ͽ���
�������׺���Ϊˮ  ��ȴ��ɽ������  ȡ�λ������ع�  ��Ե�޵���Ե
������������Ϊ���š�
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"bridge3",
	]));
	set("coor/x", 1220);
	set("coor/y", -1200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}