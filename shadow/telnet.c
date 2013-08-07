// telnet.c

#include <net/socket.h>
#include <ansi.h>

//inherit F_SHADOW;
inherit __DIR__"shadow";

static string from_user;        // �û�����������Ϣ
static int fd;                  // ����Զ�˻������׽���
static string dest_addr;        // ����Զ�˻����ĵ�ַ
static int port;                // ����Զ�˻����Ķ˿ں�

#define MAX_PENDING_INPUT               16384

// ȡ����������Ļ�������

private void send_to_remote();

void init()
{
}

int is_telneting() { return 1; }

string query_dest_addr() { return sprintf("%s %d", dest_addr, port); }

void telnet_input(string str)
{
        if (str == "CLOSE")
        {
                write("�û��Ͽ������ӡ�\n");
                destruct(this_object());
                return;
        }

        input_to("telnet_input");

        if (strlen(str) + strlen(from_user) < MAX_PENDING_INPUT)
        {
                from_user += str + "\n";
                if (find_call_out("send_to_remote") == -1)
                        send_to_remote();
        } else
                write("�������̫����...\n");
}

int accept_fight(object ob)
{
        return notify_fail("����Զ�̵�¼��...\n");
}

int accept_hit(object ob)
{
        return accept_fight(ob);
}

int accept_kill(object ob)
{
        return accept_fight(ob);
}

int accept_ansuan(object ob)
{
        return accept_fight(ob);
}

int accept_touxi(object ob)
{
        return accept_fight(ob);
}

void receive_damage(string type, int n, object from)
{
        return;
}

void receive_wound(string type, int n, object from)
{
        return;
}

void heart_beat()
{
        set_heart_beat(0);
}

void fight_ob(object ob)
{
        return;
}

void kill_ob(object ob)
{
        return;
}

void unconcious()
{
        return;
}

void die(object killer)
{
        return;
}

int clean_up()
{
        if (query_shadow_now())
                return 0;

        destruct(this_object());
        return 0;
}

void connect_to(string arg)
{
        if (sscanf(arg, "%s %d", dest_addr, port) != 2)
        {
                write("��ַ����\n");
                return;
        }

        write("������ַ��...\n");
        from_user = "";
        resolve(dest_addr, "telnet_resolve_callback");
        input_to("telnet_input");
}

void telnet_resolve_callback(string address, string resolved, int key)
{
        int ret;
        object sob;
        string full_addr;

        if (! objectp(sob = query_shadow_now()))
        {
                destruct(this_object());
                return;
        }

        while (1)
        {
                if (! resolved)
                {
                        message("telnet", "�޷�������ַ��\n", sob);
                        if (sscanf(dest_addr, "%*d.%*d.%*d.%*d") == 4)
                                resolved = dest_addr;
                        else
                                break;
                }

                full_addr = sprintf("%s %d", resolved, port);
                fd = socket_create(STREAM,
                                   "telnet_read_callback",
                                   "telnet_close_callback" );
                if (fd < 0)
                {
                        message("telnet", "SOCKET ��ʼ������\n", sob);
                        break;
                }
        
                ret = socket_connect(fd, full_addr,
                                     "telnet_read_callback",
                                     "telnet_write_callback");
                if (ret != EESUCCESS)
                {
                        message("telnet", "�������Ӵ���\n", sob);
                        break;
                }
        
                message("telnet", "��������" + address +
                                  "(" + full_addr + ")...\n", sob);
                return;
        }

        sob->write_prompt();
        destruct(this_object());
}

void telnet_read_callback(int fd, string mess)
{
        object sob;

        if (! objectp(sob = query_shadow_now()))
        {
                destruct(this_object());
                return;
        }

        if (stringp(mess))
                message("telnet", mess, sob);
}

void telnet_write_callback(int fd)
{
        if (strlen(from_user))
                send_to_remote();
}

void telnet_close_callback(int fd)
{
        object sob;

        if (objectp(sob = query_shadow_now()))
                message("telnet", HIR "���ӶϿ��ˣ��밴�س�������...\n" NOR, sob);

        destruct(this_object());
}

void remove()
{
}

void net_dead()
{
	object me=query_shadow_now();
  object link_ob;
  me->set_heart_beat(0);
  if( objectp(link_ob = me->query_temp("link_ob")) ) destruct(link_ob);
  me->remove_all_enemy();
  me->set_temp("netdead", 1);
	destruct(this_object());
}
void remove_interactive()
{
        destruct(this_object());
}

varargs string short(int raw)
{
        object sob;
        string str;

        if (objectp(sob = query_shadow_now()))
        {
                str = sob->short(raw);
                str = replace_string(str, " <����������>", " <Զ�̵�¼��>");
                return str;
        }

        return 0;
}

// ���û������������ݷ��͵�Զ�˷�������ȥ
private void send_to_remote()
{
        switch (socket_write(fd, from_user))
        {
        case EESUCCESS:
        case EECALLBACK:
                // ���ͳɹ���
                from_user = "";
                return;

        case EEWOULDBLOCK:
                // ������������
                call_out("send_to_remote", 2);
                return;

        default:
                // ����ʧ��
                return;
        }
}
