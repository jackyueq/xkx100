// Room: /d/yanping/3800kan.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "��ǧ�˰ٿ�");
	set("long", @LONG
�Թ������޳�;����������ȫ��������������������������ͨ��
��ιŵ��ųơ���ǧ�˰ٿ�����������ߣ���ʯ���ͣ����糤��������
���ѣ����Ʊ̷壬��Ϊ׳�ۡ�����ͷ����̣�ֱ��嶥�ű����ഫ��ũ
����ѡ���ʶ��꣬���ʹ�������ʮ��ʱ�俱����ƣ��������ڣ�����ʯ
�ף����޹ŵ����˳�̹;���������ʯ�������ص�������;�������ഫ��
����ǧ�˰ٿ��������лƽ𡱡�
    �ɴ��µ���������ɽ´��������ƽ�����ˡ�
LONG );
	set("exits", ([
		"northup"   : __DIR__"banyanting",
		"southdown" : __DIR__"yidao3",
	]));
	set("objects", ([
		"/d/taishan/npc/tiao-fu" : 2,
	]));
	set("outdoors", "yanping");
	setup();
	replace_program(ROOM);
}
