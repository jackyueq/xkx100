// Room: /d/fuzhou/anminxiang.c
// Last Modifyed by Evil on Sep. 10 2002

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���ƴ�ũ��������Ƴ�����ʱ�������Ｔ��ʾ���񣬹�����������
�෻������������Т�ţ���̫������Ӵ˸�Ի����Ԫ̨���¡�����ʷ��
�����˼Ҷ�Ϊ����ʹԪ��ʡ���¼�ګ��֮����������Ӿ�լ�Ա���
�ȳƸ�ֺ͹��ӷ��ϡ�
LONG );
	set("exits", ([
		"west" : __DIR__"nanhoujie5",
	]));
	set("objects", ([
		"/d/village/npc/boy" : random(2),
		"/d/village/npc/girl" : random(2),
	]));
	set("outdoors", "fuzhou");
	set("no_clean_up", 0);
	set("coor/x", 1837);
	set("coor/y", -6350);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
