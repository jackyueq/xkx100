// Room: /d/yanping/yidao3.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
�����ǽ�����������������ƽ�����ˡ����߽�Ϫ����ľ��˳��
���£��ڽ�ʯ��̲�д��У�������ӿ��������ˮ����ɢ��������ɽ
��«έ�ཻ�����˳ơ�ǧ�Ŵ�������̲��ʮ�������Ŵ��������������
��ƽ�˾��еġ��������Ρ��ˡ����˲�֪���ޣ����ֻ�ˮ����Ӱҡ�磬
�����������ɴҴҡ�
LONG );
	set("exits", ([
		"northup"   : __DIR__"3800kan",
		"southeast" : __DIR__"fengguanyan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yanping");
	setup();
	replace_program(ROOM);
}
