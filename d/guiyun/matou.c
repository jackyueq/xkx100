// Room: /guiyun/matou.c
// Date: Nov.18 1998 by Winder
#include <ansi.h>
inherit RIVER;

void create()
{
	::create();
	set("short", "��ͷ");
	set("long", @LONG
����һ���ڽ���ˮ�缫��������ͷ���ɴֲڵĴ�����ʯ��ɡ�����
�ƺ���һ�������ׯԺ������ͣ��һ�Ҵ��洬(ship)������б�ң��緫
���ţ��������Ӳ���Ϊ�˳���(hu)����������ս�õġ�
LONG );
        set("outdoors", "guiyun");
	set("no_clean_up", 0);
	set("item_desc", ([
		"ship":"����̫��ˮ���ٸ���ƶ��ս������ȥ(shang ship)�ͳ�����\n",
		"hu"  : HIC "\n�����ϴ���һҶС�ۣ�����һ�����ҹ����ڻ�����Ҳ�������("
                         HIY "yell" HIC ")һ����\n��(" HIY "boat" HIC
                        ")�����������������Ը��Ṧ����,Ҳ��ֱ��"
                        "��ˮ(" HIY "cross" HIC ")̤ˮ������\n" NOR,
	]));
	set("exits", ([
		"east" : __DIR__"road2",
	]));
	set("coor/x", 300);
	set("coor/y", -600);
	set("coor/z", 0);
  set("yell_about", "����");             // yell ����
  set("river_type", "��");               // �����ϴ�������
  set("need_dodge",300);                 // ��Ҫ�����Ṧ
  set("come_msg_out",   "һҶ���ۻ�����ʻ�˹�����������һ��̤�Ű���ϵ̰����Ա�˿����¡�\n");
  set("busy_msg",       "ֻ���ú�������������������������æ���š�����\n");
  set("wait_msg",       "����һֻ�ɴ��ϵ�������˵�������������أ������ɡ�\n");
  set("leave_msg_out",  "������̤�Ű��������������һ�㣬���������ʻȥ��\n");
  set("leave_msg_in",   "������̤�Ű���������˵��һ��������ඡ������һ�㣬���������ʻȥ��\n");
  set("come_msg_in",    "����˵���������ϰ��ɡ����漴��һ��̤�Ű���ϵ̰���\n");
  set("item_desc/river", HIC "\n�����ϴ���һҶС�ۣ�����һ�����ҹ����ڻ�����Ҳ�������("
                         HIY "yell" HIC ")һ����\n��(" HIY "boat" HIC
                        ")�����������������Ը��Ṧ����,Ҳ��ֱ��"
                        "��ˮ(" HIY "cross" HIC ")̤ˮ������\n" NOR);
  set("boat_short", "�ɴ�");    
  set("boat_desc",  @LONG
�밶��Զ����������������Ī֪���֮�ں������ֻ��Ǻ���֮����
�ء����ҹ��ڴ�β���еػ���ˮ��
LONG );
  set("to", "/d/yixing/taihu");
	setup();
}
void init()
{
	::init();
	add_action("do_shang", "shang");
}

int do_shang ( string arg )
{
	object ob ;
	string dir;
	if( !arg || arg !="ship" ) 
	{
		 tell_object(this_player() , "��Ҫ enter �Ķ���\n" ) ;
		 return 1 ;
	}
	ob = this_player () ;
	message_vision("����Ⱥ��һ��$N�ϴ���æ����һ�����������ˣ�����ඣ�ɱ��ȥ��\n", ob);
	message_vision("�������𷫣���������к��С�\n", ob);
	ob ->move("/d/guiyun/ship") ;
	tell_object(ob, CYN "���ʴ��ں�������ǰ�У�ս������.......\n" NOR ) ;
	call_out("rjinbing", 10 , ob );
	return 1 ;
}
void rjinbing( object ob )
{
	object ship, jinship;
	if(!( ship = find_object("/d/guiyun/ship")) )
		  ship = load_object("/d/guiyun/ship");
	if(!( jinship = find_object("/d/guiyun/jinship")) )
		  jinship = load_object("/d/guiyun/jinship");
	tell_object(ob , "ս����һ����ɱ����ײ������һ�Ҵ󴬡�\n" ) ;
	ship->set("exits/out", "/d/guiyun/jinship" );
	jinship->set("exits/out", "/d/guiyun/ship" );
}
