// Room: /d/fuzhou/huangxiang.c
// Last Modifyed by Evil on Sep. 10 2002

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������(307��312)��ԭ�����˼ұ����������仧�ڴˣ��ʳƻ�
��ƴ���豷����������Ƴ����븣�ݣ����Ż�豵Ĵ����������
ʿ����������������������ס����ѧʿ���������͡����֪������Ӣ��
������֦����Ѳ����𥡢�����ʦ�����ҡ���ʿ�����塢���µȣ�����
�����ڡ���������ʮ����ʱ���������ס�ľ��ǻ�豵ľɾӣ�����լ
�ڽ���С¥��ȡ����¥���Աټ�ɽ�عݣ����н���԰�ַ��ϡ�
LONG );
	set("exits", ([
		"west" : __DIR__"nanhoujie4",
	]));
	set("outdoors", "fuzhou");
	set("no_clean_up", 0);
	set("coor/x", 1837);
	set("coor/y", -6340);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
