// Room: /d/wudujiao/jiang2.c

#include <ansi.h>
inherit RIVER;

void create()
{
	::create();
        set("short", "�һ�������");
        set("long", @LONG
�������һ����ߣ���ˮ�峺��ˮ��ƽ�������������ޱߵ���
�����������һ����Ʈ�뽭�У��沨����������ͣ����һ���洬��
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"cun1",
                "south" : __DIR__"xiao1",
        ]));

	set("coor/x", -45000);
	set("coor/y", -81010);
	set("coor/z", 0);
  set("yell_about", "����");             // yell ����
  set("river_type", "��");               // �����ϴ�������
  set("need_dodge",300);                 // ��Ҫ�����Ṧ
  set("come_msg_out",   "һҶ���ۻ�����ʻ�˹�����������һ��̤�Ű���ϵ̰����Ա�˿����¡�\n");
  set("busy_msg",       "ֻ���ý�������������������������æ���š�����\n");
  set("wait_msg",       "����һֻ�ɴ��ϵ�������˵�������������أ������ɡ�\n");
  set("leave_msg_out",  "������̤�Ű��������������һ�㣬��������ʻȥ��\n");
  set("leave_msg_in",   "������̤�Ű���������˵��һ��������ඡ������һ�㣬��������ʻȥ��\n");
  set("come_msg_in",    "����˵���������ϰ��ɡ����漴��һ��̤�Ű���ϵ̰���\n");
  set("item_desc/river", HIC "\nֻ����������һ���洬��Ҳ�������("
                         HIY "yell" HIC ")һ������(" HIY "boat" HIC
                        ")��\n���������������Ը��Ṧ����,Ҳ��ֱ��"
                        "��ˮ(" HIY "cross" HIC ")̤��������\n" NOR);
  set("boat_short", "�ɴ�");    
  set("boat_desc",  @LONG
һҶС�ۣ����Ҳ�������ߡ��˸��ˡ�һ����ʮ�����������
�ֳֳ���ݣ����ڴ�β�����س��Ŵ���
LONG );
  set("to",         __DIR__"jiang1");  // �����յ� /*   ��ѡ   */
	setup();
}