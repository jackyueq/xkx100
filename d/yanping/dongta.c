// Room: /d/yanping/dongta.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����������������ʮ�������£�����������ɽ�����߾��ɣ�ͬ����
ʽ��װ����ȫһ�������߲�˽�ʵ����ʯ�����ഫ��ʱ�������֣��ٱ�
ɽ������ˮ�����˱��������»����ý�������Ϫ�ڴ˽����硰�ˡ��֣�
�㽨��˫�������ɡ������Σ��Ի���а������
LONG );
	set("exits", ([
		"northdown" : __DIR__"liyuding",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yanping");
	setup();
	replace_program(ROOM);
}
