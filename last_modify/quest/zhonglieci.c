// /d/city/zhonglieci.c  ������
//modified by sega 1/10/99
//�޸�a_timeΪ120,�����newjob��һЩ��Ϣ,�Է�һЩ��һֱflood
//�޸�a_timeΪ300��һЩ����ҽ��������ӳ����ʱ�䡣
//�޸���2�α��ڼ��Ϊ5����
#include <ansi.h>
#define A_TIME 300 
inherit ROOM;

string * add_msg = ({
	"/d/city/siqiaoyanyu",		// ��������
	"/d/city2/wangfu1",		// ���������
	"/d/city3/wangjianglou",	// ����¥
	"/d/suzhou/canlangting",	// ����ͤ
	"/d/hangzhou/liulangqiao",	// ������
	"/d/fuzhou/yongquan",		// ӿȪ��
	"/d/xiangyang/nixianglou",	// ����¥
	"/d/lingzhou/luorilin1",	// ������
	"/d/dali/feilihu",		// ��������
	"/d/village/temple1",		// ��̳��
//	"/d/shaolin/qyping",		// ����ƺ
	"/d/wudang/sanqingdian",	// �����
	"/d/jiangling/chenglingji",	// �����
	"/d/emei/duguangtai",		// �ù�̨
	"/d/qingcheng/huyingting",	// ��Ӧͤ
	"/d/songshan/luyanpubu",	// «���ٲ�
	"/d/taishan/tanhai",		// ̽��ʯ
	"/d/huashan/ziqitai",		// ����̨
	"/d/henshan/liuyunping",	// ����ƺ
	"/d/hengshan/tongyuangu",	// ͨԪ��
	"/d/mingjiao/shanlu3",		// ������
	"/d/heimuya/xingxingtan",	// ����̲
	"/d/xuedao/wangyougu",		// ���ǹ�
	"/d/gumu/taiyi1",		// ̫�ҳ�
//	"/d/taohua/xiuxishi",		// �һ���
	"/d/baituo/zhuyuan",		// ��԰
	"/d/xiaoyao/qingcaop",		// ���ƺ
	"/d/xiaoyao/pubu",		// ����ٲ�
//	"/d/lingjiu/daban",		// ׺����
//	"/d/xingxiu/yueerquan",		// �¶�Ȫ
	"/d/xueshan/cangjingge",	// ѩɽ�ؾ���
	"/d/wudujiao/taohua",		// �һ���
	"/d/wuliang/jianhugong",	// ������
        "/d/jiangling/shennongjia",     // ��ũ��
        "/d/kunlun/kuhanlou",           // �ຮ¥
        "/d/shaolin/damodong",          // ��Ħ��
        "/d/wudang/shierliantai",       // ʮ����̨
        "/d/qingcheng/maguchi",         // ��ó�
        "/d/lanzhou/cuiying",           // ��Ӣ��
        "/d/city/ouyangci",             // ŷ����
	"/d/tianlongsi/yuhuayuan",	// �껨Ժ
	"/d/yanziwu/tingxiang",		// ����ˮ�
        "/d/quanzhen/shijianyan",       // �Խ���
        "/d/lingzhou/luorilin1",        // ������
        "/d/huanghe/wuqiao",            // ������
        "/d/changcheng/fenghuotai1-2",  // ���̨
        "/d/changcheng/fenghuotai1-1",  // ���̨
	"/d/meizhuang/xiaoyuan",	// ����СԺ
	"/d/shiliang/tingzi",		// õ��Сͤ
});

void create()
{
	set("short", "������");
	set("long", @LONG
�����������������Ǵ���¹����ΤС������ʥ�濵��ʥ����������
���ȴ�Ǵ������ұ������Ҿ���������ݶ�ʦʷ��ʷ�ɷ�����������
�ǿ������ʡ�뷽�������������������ʷ����������������ϵ���ɫ
�Ѿ��ವ�����ˡ����ܵĵ��ϻ���һЩ���������������Ѿ���Щʱ��û
���������ĺۼ�����ǰ�ڷ���һ�ź�ľ�߽Ź��������ϸߴ�������һ��
����(kan)��
LONG    );
	set("no_fight",1);
	set("no_clean_up",1);
	set("exits", ([
	     "northeast" : __DIR__"caohebeijie",
	]));

	set("count",1);
	set("item_desc", ([
		"kan" :  HIG"
������һ�Ƚϣ��㷢���������һ����Ⱦ���ɾ�����֣��������˴��Ƶġ�\n
"NOR
	]));
	set("coor/x",-20);
	set("coor/y",-10);
	set("coor/z",0);
	set("coor/x",-20);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}

void init()
{
	add_action("do_open","dakai");
	add_action("do_open","open");

	remove_call_out("newjob");
	call_out("newjob",A_TIME);
}

int do_open(string arg)
{
	object me = this_player();
	object ob,rz;
	string src_add,dest_add,des;
	object room,room2;

	src_add=add_msg[random(sizeof(add_msg))];
	dest_add=add_msg[random(sizeof(add_msg))];
	while (dest_add == src_add)
		dest_add=add_msg[random(sizeof(add_msg))];

	if (!arg || arg != "kan" )
		return 0;

	if (me->query_skill("dodge", 1) < 80)
		return notify_fail("����̫���ˣ�����Ṧ�����š�\n");

	if ( !wizardp(me) && time() - me->query("baobiaotime") < 300)
		return notify_fail("����ϸ���������ˣ��������ࡣЪ��ɡ�\n");

	if (query("count") > 0) {
		if (!present("mi ling",me) ) {
			if (! room = find_object(src_add) )
				room = load_object(src_add);
			rz = new(__DIR__"npc/renzhi");
			rz -> set("leader_name", me->query("id") );
			rz -> set("title",me->query("name")+"������������");
			rz -> set("dest_add",dest_add);
			rz -> move(room);
			if (! room2 = find_object(dest_add) )
				room2 = load_object(dest_add);
			des = "����" + room->query("short") + "�����" + rz->query("name") + "����" + room2->query("short") ;
			ob = new(__DIR__"obj/miling");
			ob -> set("describe",des);
			ob -> set("src_add",room->query("short") );
			ob -> set("dest_add",room2->query("short") );
			ob -> set("src_des",room->query("outdoors") );
			ob -> set("dest_des",room2->query("outdoors") );
			ob -> move(me);
			me -> set("baobiaotime", time());
			add("count",-1);
message_vision(HIY"$NС������ش����裬������һ��ֽ��������ź�ľ�����˳��ȡ�����������С�\n"NOR,me);
			return 1;
		}
		else
		{
message_vision(YEL"$N����Ҫ�����裬һ��С�ģ�������䡯��һ�¹����������ˡ�\n"NOR,me);
			return 1;
		}
	}
	else {
message_vision(HIG"$NС������ش����裬����������ɶ��û�С�����˭�������أ����������ɡ�\n"NOR,me);
		return 1;
	}
}

void newjob()
{
	object room;
	if (query("count") <= 0) {
		if( room = find_object(__DIR__"zhonglieci") )
		message("vision",YEL"ֻ��һ���м����ɵĻ��������˽��������������ﵷ���˼��£�������ŵ����ˡ�\n"NOR,room);
		add("count",1);
	}
	remove_call_out("newjob");
	call_out("newjob",A_TIME);
}

