// Room: /d/yanping/xiagu.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "ϪԴϿ��");
	set("long", @LONG
ϪԴϿ�ȡ�ԭʼ������Ȼ���������Ĺȼ׶��ϡ����˵�֮ˮ���仯
��ˡ������������ļ�����Ҳ��������ʵ�ϸ�������ڿշ�д���ٲ���
Ҳ�����Ʈ����ˮ���������������������Ҳ��Ǳ�����ҵ���Ȫ��ʮ��
Ϫɽ��ɽ��ˮɫ�����½�ӳ������һ����Ȼˮī����
LONG );
	set("exits", ([
		"northup"   : __DIR__"xiyuanan",
		"southeast" : __DIR__"youlang",
	]));
	set("outdoors", "yanping");
	set("no_clean_up", 0);
	set("coor/x", 1420);
	set("coor/y", -6130);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
